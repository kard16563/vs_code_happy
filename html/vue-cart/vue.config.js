module.exports={

    configureWebpack:{
        devServer:{
            before(app){//前置中间件 服务器启动之前
                //npm i axios -s 安装 axios

                app.get('/app/goods',function(req,res){
                    res.json({//假设后台返回json
                        code:0,
                        list:[
                        {id:1,text:'1---',price:551}, //做假数据 
                        {id:2,text:'2---',price:552},
                        {id:3,text:'3---',price:553},
                        {id:4,text:'4---',price:554},
                        {id:5,text:'5---',price:555},
                        ]

                    })


                })


            }
        }
    }
}