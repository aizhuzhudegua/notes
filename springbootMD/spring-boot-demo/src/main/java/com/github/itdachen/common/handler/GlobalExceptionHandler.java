package com.github.itdachen.common.handler;

import com.github.itdachen.common.exception.BizException;
import com.github.itdachen.common.response.ServerResponse;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.HttpStatus;
import org.springframework.util.StringUtils;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

import javax.servlet.http.HttpServletResponse;

/**
 * Description: 全局异常统一处理
 * Created by 王大宸 on 2023-08-12 17:23
 * Created with IntelliJ IDEA.
 */
// com.github.itdachen 是你需要监听的包的范围, 这里是说监听 com.github.itdachen.xx 下所有的包
// 大家根据自己的包名, 填写自己的包路径
@RestControllerAdvice(basePackages = {"com.github.itdachen"})
public class GlobalExceptionHandler {
    private static final Logger logger = LoggerFactory.getLogger(GlobalExceptionHandler.class);

    /**
     * 统一异常处理,自定义抛出异常
     */
    @ExceptionHandler(BizException.class)
    public ServerResponse<String> bizExceptionHandler(HttpServletResponse response, BizException ex) {
        response.setStatus(HttpStatus.OK.value());
        if (StringUtils.isEmpty(ex.getMessage())) {
            return ServerResponse.errMsg("出现未知错误,请联系技术人员!");
        }
        return ServerResponse.errMsg(ex.getMessage());
    }

    /**
     * 其他异常
     */
    @ExceptionHandler(Exception.class)
    public ServerResponse<String> baseExceptionHandler(HttpServletResponse response, Exception ex) {
        response.setStatus(HttpStatus.OK.value());
        if (StringUtils.isEmpty(ex.getMessage())) {
            return ServerResponse.errMsg("未知错误,请联系管理员");
        }
        return ServerResponse.errMsg(ex.getMessage());
    }


}
