package com.org.xidian;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

import java.io.IOException;

public class GrandchildGrandparent {

    public static class MyMapper extends Mapper<Object, Text, Text, Text> {

        @Override
        protected void map(Object key, Text value, Context context) throws IOException, InterruptedException {
            // 父，子
            String line = value.toString();
            String[] names = line.split(",");
            String child = names[1];
            String parent = names[0];
	    context.write(new Text(child), new Text("+" + parent));
	    context.write(new Text(parent), new Text("-" + child));
        }
    }

    public static class MyReducer extends Reducer<Text, Text, Text, Text> {

        @Override
        protected void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
            
            ArrayList<Text> parents = new ArrayList<>();
            ArrayList<Text> children = new ArrayList<>();

            for (Text value : values) {
                String valueString = value.toString();
                // 通过字符前缀检测是child还是parent
                if (valueString.startsWith("+")) {
                    parents.add(new Text(valueString.substring(1)));
                }
                if (valueString.startsWith("-")) {
                    children.add(new Text(valueString.substring(1)));
                }
            }
            for (Text grandparent : parents) {
                for (Text grandchild : children) {
                    context.write(new Text(grandparent), new Text(grandchild));
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf, GrandchildGrandparent.class.getSimpleName());
        job.setJarByClass(GrandchildGrandparent.class);


        FileInputFormat.setInputPaths(job, args[0]);

        job.setMapperClass(MyMapper.class);

        job.setMapOutputKeyClass(Text.class);
        job.setMapOutputValueClass(Text.class);

        job.setReducerClass(MyReducer.class);
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(Text.class);
        FileOutputFormat.setOutputPath(job, new Path(args[1]));

        job.waitForCompletion(true);
    }
}

