import functools
from flask import (
    Blueprint, flash, g, redirect, render_template, request, session, url_for
)
from werkzeug.security import check_password_hash, generate_password_hash

from AIdotX.db import get_db

bp = Blueprint('auth', __name__, url_prefix='/auth')

@bp.route('/register_new_user', methods=('GET', 'POST'))
def register_new_user():
    return render_template('auth/register_new_user.html')

@bp.route('/user_login', methods=('GET','POST'))
def user_login():
    return render_template('auth/user_login.html')