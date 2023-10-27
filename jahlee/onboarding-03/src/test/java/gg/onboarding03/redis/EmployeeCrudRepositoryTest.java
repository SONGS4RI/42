package gg.onboarding03.redis;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class EmployeeCrudRepositoryTest {
    @Autowired private EmployeeCrudRepository redisRepository;

    @Test
    void save() {
        EmployeeRedisEntity employee = new EmployeeRedisEntity(0, "zero", 1);
        redisRepository.save(employee);
    }

}