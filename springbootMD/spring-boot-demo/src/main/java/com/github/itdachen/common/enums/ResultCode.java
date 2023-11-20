package com.github.itdachen.common.enums;

/**
 * Description:
 * Created by 王大宸 on 2023-08-12 17:02
 * Created with IntelliJ IDEA.
 */
public enum ResultCode {

    // 操作成功
    SUCCESS(true, 200, "操作成功！"),
    // 操作失败
    ERROR(false, 500, "操作失败！"),


    ;

    // 响应是否成功
    private final Boolean success;
    // 响应状态码
    private final Integer status;
    // 响应信息
    private final String message;

    ResultCode(Boolean success, Integer status, String message) {
        this.success = success;
        this.status = status;
        this.message = message;
    }

    public Boolean getSuccess() {
        return success;
    }

    public Integer getStatus() {
        return status;
    }

    public String getMessage() {
        return message;
    }


}
