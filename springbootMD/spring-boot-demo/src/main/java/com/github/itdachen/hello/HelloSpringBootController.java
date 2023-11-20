package com.github.itdachen.hello;

import com.github.itdachen.common.exception.BizException;
import com.github.itdachen.common.response.ServerResponse;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

/**
 * Description: Hello Spring Boot
 * Created by 王大宸 on 2023-08-12 16:13
 * Created with IntelliJ IDEA.
 */
@Controller
@RequestMapping("/hello")
public class HelloSpringBootController {


    /***
     * helloSpringBoot
     * 访问地址: http://127.0.0.1:8080/hello/spring/boot
     *
     * @author 王大宸
     * @date 2023/8/12 16:15
     * @return java.lang.String
     */
    @GetMapping("/spring/boot")
    @ResponseBody
    public String helloSpringBoot() {
        return "Hello Spring Boot";
    }


    /***
     * 统一返回数据格式
     * 访问地址: http://127.0.0.1:8080/hello/server/response
     * @author 王大宸
     * @date 2023/8/12 17:12
     * @return com.github.itdachen.common.response.ServerResponse<java.lang.String>
     */
    @GetMapping("/server/response")
    @ResponseBody
    public ServerResponse<String> helloServerResponse() {
        return ServerResponse.okData("Hello Spring Boot");
    }

    /***
     * 自定义异常测试
     * 访问地址: http://127.0.0.1:8080/hello/server/exception
     * @author 王大宸
     * @date 2023/8/12 17:21
     * @return com.github.itdachen.common.response.ServerResponse<java.lang.String>
     */
    @GetMapping("/server/exception")
    @ResponseBody
    public ServerResponse<String> helloException() throws Exception {
        throw new BizException("呀, 这里出现了一个异常！！！");
    }



}
