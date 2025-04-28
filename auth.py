import functools
from flask import (
    Blueprint, flash, g, redirect, render_template, request, session, url_for
)
from werkzeug.security import check_password_hash, generate_password_hash

from AIdotX.db import get_db

bp = Blueprint('auth', __name__, url_prefix='/auth')

@bp.route('/register_new_user', methods=('GET', 'POST'))
def register_new_user():
    if request.method == 'POST':
        email = request.form['email']
        username = request.form['username']
        password = request.form['password']
        db = get_db()
        error = None
        import re

        is_valid_email = bool(re.match(r"^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$", email))
        
        if not username:
            error = 'Username is required.'
        elif not password:
            error = 'Password is required.'
        elif not email:
            error = 'Email is required.'
            
        if not is_valid_email:
            error = 'Email is not valid.'

        if error is None:
            try:
                db.execute(
                    "INSERT INTO user (email, username, password, balance) VALUES (?, ?, ?, ?)",
                    (email, username, generate_password_hash(password), 0),
                )
                db.commit()
            except db.IntegrityError:
                error = f"User {username} or Email {email} is already registered."
            else:
                return redirect(url_for("auth.login"))

        flash(error)

    return render_template('auth/register_new_user.html')

@bp.route('/user_login', methods=('GET','POST'))
def user_login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        db = get_db()
        error = None
        user = db.execute(
            'SELECT * FROM user WHERE username = ? or email = ?', (username, username)
        ).fetchone()
        
        if user is None:
            error = 'Incorrect username.'
        elif not check_password_hash(user['password'], password):
            error = 'Incorrect password.'

        if error is None:
            session.clear()
            session['user_id'] = user['id']
            if user['balance'] == 0:
                return redirect(url_for('jokes.create'))
            return redirect(url_for('index'))

        flash(error)

    return render_template('auth/user_login.html')

@bp.before_app_request
def load_logged_in_user():
    user_id = session.get('user_id')

    if user_id is None:
        g.user = None
    else:
        g.user = get_db().execute(
            'SELECT * FROM user WHERE id = ?', (user_id,)
        ).fetchone()

@bp.route('/logout')
def logout():
    session.clear()
    return redirect(url_for('index'))