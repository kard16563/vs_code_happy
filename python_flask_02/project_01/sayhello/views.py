from flask import flash ,redirect,url_for,render_template
from sayhello import app

#print(123456)
# @app.route("/")
# def index():
#     print(123)    
#     #return '<h1> hello world <h1>'
#     return render_template('index.html')
#     #return render_template("index2.html")
from flask import flash, redirect, url_for, render_template

from sayhello import app
from sayhello.forms import HelloForm
from sayhello.models import Message

@app.route('/', methods=['GET', 'POST'])
def index():
    form = HelloForm()
    if form.validate_on_submit():
        name = form.name.data
        body = form.body.data
        message = Message(body=body, name=name)
        # db.session.add(message)
        # db.session.commit()
        flash('Your message have been sent to the world!')
        return redirect(url_for('index'))

    messages = Message.query.order_by(Message.timestamp.desc()).all()
    #return render_template('index2.html')#for test 
    return render_template('index.html', form=form, messages=messages)

@app.route('/b', methods=['GET', 'POST'])
def bootstrap():
    print('bootstrap')
    return render_template('bootstrap.html')

    