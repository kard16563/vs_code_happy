<template>
    <div>
        <!--form组件 绑定数据模型 添加校验规则 他里面有 formitem组件 这个里面有 label 和 prop--->
        <!----formitem组件 里面有 input组件 -------->
        
        <h3> {{title}} ---- {{tit}}</h3>
        <!---model 数据模型 rules 表单的验证规则 ref(reference)参考 起个别名供下面使用  --->
        <el-form :model="ruleform" :rules="rules" ref="loginform" >
            <!--prop 用与校验 若没有校验就不用  --->
            
            <el-form-item label='username' prop='name'>
                <!---v-model 进行双向绑定 绑定模型的name --->
                <el-input v-model="ruleform.name" ></el-input>
            </el-form-item>
            <el-form-item label='password' prop='pwd'>
                <el-input v-model="ruleform.pwd" ></el-input>
            </el-form-item>
            <el-form-item>
                <el-button  type='primary' @click="submit()">登录</el-button>
            </el-form-item>
        </el-form>
        <br><br>

    <self_from :model="ruleform" :rules="rules" ref="loginform2" >
        <kform lable="用户名" prop="name" ><!-----校验规则为 本文件下的 rules的name------>
            <dinput v-model="ruleform.name" ></dinput>
        </kform>
        <kform lable="pass" prop="pwd" ><!------//校验规则为 本文件下的 rules的pwd----->
            <dinput v-model="ruleform.pwd" type="password" ></dinput>
            <!-----//dinput 没有type 去添加----->
            <el-button type="primary" @click="submit2()" >login </el-button>
        </kform>
    </self_from>
{{ruleform}}
        <!-- 自定义组件应用 -->
        <h1>自定义组件应用</h1> 
        <dinput v-model="somevelues"></dinput>
        {{somevelues}}

    </div>



</template>

<script>
import des_input from './input';// add  components  
import form_item from './self_form_item';
import self_from from'./self_form'

    export default {
        props:{
            title:{ type:String,required:true,default:'defaule' },
            //传输的数据类型  是否必须  默认值
            tit:{type:String,default:'tit'}
        },//用于接收老爹的东西
        components:{
            dinput:des_input,
            kform :form_item,
            self_from
        
        },// add components
        data() {
            return {
                somevelues:'自定义 组件',
                ruleform: {
                    name:"",
                    pwd:""
                },// 上面有模型名
                rules:{
                    name:[{ required:true ,message:"please input  your mane" },
                            {min:6,max:10,message:"please input the username by 6 to 10 character "}
                        ],
                    pwd:[{required:true,message:"please input your password customized by yourself"}]
                }//上面有校验名
            }
        },
        methods: {
            submit() {
                this.$refs.loginform.validate(valid=>{
                    if (valid) {
                        alert('login successfully!');
                        
                    }else{
                        window.console.log('validate false')
                        return false;
                    }
                })
                
            },
            
            submit2(){

                this.$refs.loginform2.validate(valid=>{
                    //在self_form 有validate 方法  46行 并传入了回调函数  接受布尔值valid
                    if (valid) {
                        alert('login successfully!');
                        
                    }else{
                        window.console.log('validate false')
                        return false;
                    }
                })

                //alert(this.ruleform);
            }
        },

        
    }
</script>

<style>

</style>