from flask import Flask,render_template

app = Flask(__name__,template_folder='templates')

@app.route("/")
def hello():
    print(123)    
    
    return '123'

if __name__ == '__main__':
    app.run()
