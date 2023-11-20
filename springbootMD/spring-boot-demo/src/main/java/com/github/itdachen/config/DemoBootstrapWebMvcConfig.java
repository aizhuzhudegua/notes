package com.github.itdachen.config;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.ResourceHandlerRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;


/**
 * Description:
 * Created by 王大宸 on 2023-08-12 18:42
 * Created with IntelliJ IDEA.
 */
@Configuration
public class DemoBootstrapWebMvcConfig implements WebMvcConfigurer {
    private static final Logger logger = LoggerFactory.getLogger(DemoBootstrapWebMvcConfig.class);

    @Override
    public void addResourceHandlers(ResourceHandlerRegistry registry) {
        /* 将请求路径为 /static/ 的路径, 都映射到 resources/static 文件夹 */
        registry.addResourceHandler("/static/**")
                .addResourceLocations("classpath:/static/");
    }


}
