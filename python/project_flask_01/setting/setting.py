from flask_sqlalchemy import SQLAlchemy
import app
##数据库配置处理 ++++=>>>  mysql+pymysql://root:用户登录密码@服务器:端口/用户的数据库
app.config['SQLALCHEMY_DATABASE_URI'] = 'mysql+pymysql://root:123456@localhost:3306/test'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app, use_native_unicode='utf8')