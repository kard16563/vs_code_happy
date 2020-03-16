public class DAO {

    public void generate() {

        ConfigModel cm=ConfigManager.get_instance().get_config_data();
        if (cm.is_need_gen_dao()) {
            System.out.println("正在生成数据层代码");
        }

    }

}
