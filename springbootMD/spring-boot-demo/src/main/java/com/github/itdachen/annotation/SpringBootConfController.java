package com.github.itdachen.annotation;

import com.github.itdachen.common.handler.IgnoreResponseAdvice;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

/**
 * Description:
 * Created by 王大宸 on 2023-08-12 16:48
 * Created with IntelliJ IDEA.
 */
@RestController

public class SpringBootConfController {

    @Value("${fly.version:0}")
    private String version;

    @Autowired
    private SpringBootConfig springBootConfig;

    /**
     * http://127.0.0.1:8080/version
     */
    @GetMapping("/version")
    public String version() {
        return version;
    }

    /**
     * http://127.0.0.1:8080/config/version
     */
    @GetMapping("/config/version")
    public String configVersion() {
        return springBootConfig.getVersion();
    }


    /**
     * http://127.0.0.1:8080/path/2
     */
    @GetMapping("/path/{id}")
    @IgnoreResponseAdvice
    public Integer ConfigVersion(@PathVariable("id") Integer id) {
        return id;
    }

    /**
     * http://127.0.0.1:8080/params?page=1&limit=10
     * @param page
     * @param limit
     * @return
     */
    @GetMapping("/params")
    public String getOpList(@RequestParam(value = "page", required = false) Integer page,
                            @RequestParam(value = "limit", required = false) Integer limit) {
        return "page: " + page + ", limit: " + limit;
    }

}
