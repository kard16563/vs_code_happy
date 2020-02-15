from flask import Flask
from flask_bootstrap import Bootstrap
from flask_moment import Moment
from flask_sqlalchemy import SQLAlchemy

import setting as set
app=Flask('project_flask_01')

#app=Flask('project_flask')
app.config.from_object(set)
#app.config.from_pyfile('set')#add config
app.jinja_env.trim_blocks = True#去掉Jinja2语句占据的空行 
# remove the Whitespace of jinja codes
app.jinja_env.lstrip_blocks=True

#app=Flask('project_flask_01')

db=SQLAlchemy(app)
bootstrap=Bootstrap(app)
moment=Moment(app)

import views ,commands,error
#from project_flask_01 import views,commands,error

