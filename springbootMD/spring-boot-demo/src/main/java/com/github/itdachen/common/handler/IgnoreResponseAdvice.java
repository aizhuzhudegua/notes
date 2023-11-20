package com.github.itdachen.common.handler;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * Description: IgnoreResponseAdvice
 * Created by 王大宸 on 2023-08-15 17:14
 * Created with IntelliJ IDEA.
 */
@Retention(RetentionPolicy.RUNTIME) // 运行时有效
@Target({ElementType.METHOD}) // 可以作用在方法上
public @interface IgnoreResponseAdvice {
}
