package com.github.itdachen;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

/**
 * Description:
 * Created by 王大宸 on 2023-08-12 15:46
 * Created with IntelliJ IDEA.
 */
@SpringBootApplication
@MapperScan(basePackages = "com.github.itdachen.**.mapper")
public class SpringBootDemoBootstrap {

    public static void main(String[] args) {
        SpringApplication.run(SpringBootDemoBootstrap.class);
        System.out.println("http://127.0.0.1:8080/student/info/index");
    }

}