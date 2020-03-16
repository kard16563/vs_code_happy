public class Business {
    public void generate() {

        ConfigModel cm = ConfigManager.get_instance().get_config_data();
        if(cm.is_need_gen_business()) {
            System.out.println("正在生成逻辑层代码");
        }

    }

}
