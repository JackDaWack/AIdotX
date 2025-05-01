from flask import (
    Blueprint, flash, g, redirect, render_template, request, url_for, session
)
from werkzeug.exceptions import abort

from MOJ.auth import login_required, user_role_required
from MOJ.db import get_db

bp = Blueprint('jokes', __name__)

@bp.route('/')
@login_required
def index():
    if g.user:
        return redirect(url_for('game.options'))
    flash("Access denied for non-users.")
    return redirect(url_for('auth.user_login'))

def play():
    return render_template(url_for('game.play'))

#def update():