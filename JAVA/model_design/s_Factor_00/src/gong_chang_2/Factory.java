package gong_chang_2;

/*简单工厂  3-建立工厂 进行封装*/

/*简单工厂   用配置文件 的*/

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;


public class Factory {

    public static api2 createapi2() {

        Properties p=new Properties();
        InputStream in =null;

        try {
            in=Factory.class.getResourceAsStream(
                    "FactoryTest.properties");
            p.load(in);//		《---------			加载数据
            System.out.println("p-> "+ p);
        } catch (IOException e) {
            // TODO: handle exception
            System.out.print("wrong---->");
            e.printStackTrace();
        }finally {
            try {
                in.close();//			<-----------	关闭数据
            } catch (IOException e2) {
                // TODO: handle exception
                System.out.print("\n wrong2--->");
                e2.printStackTrace();
            }
        }
        api2 appi2=null;

        try {
            appi2 = (api2) Class.forName(p.getProperty("ImpClass")).newInstance();
            /* p.getProperty("ImpClass") 读取数据key为ImpClass */
            System.out.println("appi2->"+appi2);
        } catch (InstantiationException e) {
            // TODO: handle exception
            e.printStackTrace();
        }catch (IllegalAccessException e) {
            // TODO: handle exception
            e.printStackTrace();
        }catch (ClassNotFoundException e) {
            // TODO: handle exception
            e.printStackTrace();
        }

        return appi2;//返回 实例

    }

}
