package com.github.itdachen.hello;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

/**
 * Description:
 * Created by 王大宸 on 2023-08-12 17:39
 * Created with IntelliJ IDEA.
 */
@Controller
@RequestMapping("/hello")
public class HelloTemplatesController {

    @GetMapping("/template")
    public String helloTemplates() {
        return "index";
    }

}
