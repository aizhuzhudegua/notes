package com.github.itdachen.hello;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

/**
 * Description:
 * Created by 王大宸 on 2023-08-12 18:41
 * Created with IntelliJ IDEA.
 */
@Controller
@RequestMapping("/hello")
public class HelloLayuiController {

    /***
     * helloLayui
     * 访问地址: http://127.0.0.1:8080/hello/layui
     * @author 王大宸
     * @date 2023/8/12 18:44
     * @return java.lang.String
     */
    @GetMapping("/layui")
    public String helloLayui() {
        return "layui";
    }

}
