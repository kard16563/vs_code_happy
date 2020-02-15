from app import app,db
from forms import HelloForm
from models import Message

@app.route('/',methods=['GET','POST'])
def index():
    form= HelloForm()
    if form.validate_on_submit():
        name = form.name.data
        body = form.body.data
        message = Message(body=body,name=name) 
        db.session.add(message)
        db.session.commit()
        flash('****')
        print('ok------>')
        return redirect(url_for('index'))
        
    messages = Message.query.order_by(Message.timestamp.desc()).all()
    return render_template('index.html', form=form, messages=messages)
    