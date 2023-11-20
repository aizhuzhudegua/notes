package com.github.itdachen.common.response;

import com.github.itdachen.common.enums.ResultCode;

import java.io.Serializable;

/**
 * Description: 返回结果格式
 * Created by 王大宸 on 2023-08-12 17:04
 * Created with IntelliJ IDEA.
 */
public class ServerResponse<T> implements Serializable {
    private static final long serialVersionUID = 8540566017796274461L;
    /**
     * 是否成功
     */
    private Boolean success = true;
    /**
     * 状态:
     */
    private Integer status = 200;
    /**
     * 消息
     */
    private String msg = "操作成功";
    /**
     * 数据
     */
    private T data;

    private ServerResponse() {
    }

    public ServerResponse(Boolean success, Integer status, String msg, T data) {
        this.success = success;
        this.status = status;
        this.msg = msg;
        this.data = data;
    }

    /**
     * 操作成功
     */
    public static <T> ServerResponse<T> ok() {
        return new ServerResponse<T>(ResultCode.SUCCESS.getSuccess(), ResultCode.SUCCESS.getStatus(), ResultCode.SUCCESS.getMessage(), null);
    }

    public static <T> ServerResponse<T> okData(T data) {
        return new ServerResponse<T>(ResultCode.SUCCESS.getSuccess(), ResultCode.SUCCESS.getStatus(), ResultCode.SUCCESS.getMessage(), data);
    }

    public static <T> ServerResponse<T> okMsgData(String msg,T data) {
        return new ServerResponse<T>(ResultCode.SUCCESS.getSuccess(), ResultCode.SUCCESS.getStatus(), msg, data);
    }

    /**
     * 操作错误
     */
    public static <T> ServerResponse<T> err() {
        return new ServerResponse<T>(ResultCode.ERROR.getSuccess(), ResultCode.ERROR.getStatus(), ResultCode.ERROR.getMessage(), null);
    }

    public static <T> ServerResponse<T> errMsg(String msg) {
        return new ServerResponse<T>(ResultCode.ERROR.getSuccess(), ResultCode.ERROR.getStatus(), msg, null);
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    public Boolean getSuccess() {
        return success;
    }

    public void setSuccess(Boolean success) {
        this.success = success;
    }

    public Integer getStatus() {
        return status;
    }

    public void setStatus(Integer status) {
        this.status = status;
    }

    public String getMsg() {
        return msg;
    }

    public void setMsg(String msg) {
        this.msg = msg;
    }

}
