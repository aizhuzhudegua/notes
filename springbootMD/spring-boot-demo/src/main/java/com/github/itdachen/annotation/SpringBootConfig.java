package com.github.itdachen.annotation;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.Configuration;

/**
 * Description:
 * Created by 王大宸 on 2023-08-12 16:51
 * Created with IntelliJ IDEA.
 */
@Configuration
@ConfigurationProperties(prefix="fly")
public class SpringBootConfig {

    private String version;

    public String getVersion() {
        return version;
    }

    public void setVersion(String version) {
        this.version = version;
    }
}
