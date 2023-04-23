import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartFrame;
import org.jfree.chart.JFreeChart;
import org.jfree.data.category.DefaultCategoryDataset;

public class test {
    public static void main(String[] args) {
        // 创建一个数据集
        DefaultCategoryDataset dataset = new DefaultCategoryDataset();
        dataset.addValue(100, "北京", "苹果");
        dataset.addValue(200, "上海", "苹果");
        dataset.addValue(150, "广州", "苹果");
        dataset.addValue(120, "北京", "梨子");
        dataset.addValue(140, "上海", "梨子");
        dataset.addValue(110, "广州", "梨子");

        // 创建一个折线图
        JFreeChart chart = ChartFactory.createLineChart(
            "水果销售统计",     // 图表标题
            "城市",            // X 轴标签
            "销售量（单位：箱）", // Y 轴标签
            dataset           // 数据集
        );

        // 创建一个图表框架并显示图表
        ChartFrame frame = new ChartFrame("水果销售统计", chart);
        frame.pack();
        frame.setVisible(true);
    }
}
