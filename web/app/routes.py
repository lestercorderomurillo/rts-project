from app import app
from flask import render_template

@app.route('/')
@app.route('/home')
def index():
  return render_template("def.html") 

@app.errorhandler(404) 
def not_found(e): 
  return render_template("404.html") 

@app.route('/user/<user>')
def hello(user=None):
    return render_template('profile.html', user=user)