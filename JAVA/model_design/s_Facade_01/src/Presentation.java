/* 一般写法
 *
 * 2->3 */

public class Presentation {

    public void generate() {
        ConfigModel cm= ConfigManager.get_instance().get_config_data();

        if (cm.is_need_gen_presentation()) {
            System.out.println("正在生成表现层代码文件");
        }

    }
}
