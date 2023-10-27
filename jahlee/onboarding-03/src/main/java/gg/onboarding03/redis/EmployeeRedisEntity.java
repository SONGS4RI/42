package gg.onboarding03.redis;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;
import org.springframework.data.redis.core.RedisHash;

import javax.persistence.Id;
import java.io.Serializable;

@Getter @Setter
@AllArgsConstructor
@RedisHash(value = "employee")
public class EmployeeRedisEntity {
//    private static final long serialVersionUID = -7817224776021728682L;
    private Integer id;
    private String name;
    private int salary;
}

