package gg.onboarding03.redis;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;
import org.springframework.data.redis.core.RedisHash;

import javax.persistence.Id;

@Getter @Setter
@AllArgsConstructor
@RedisHash(value = "address", timeToLive = 30)
public class AddressRedisEntity {
    @Id
    private String name;
    private String city;
    private String street;
    private String zipCode;
}

