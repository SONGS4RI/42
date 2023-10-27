package gg.onboarding03.redis;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class EmployRepositoryStringImplTest {
    @Autowired
    EmployeeRepositoryStringImpl employRepositoryString;
    @Test
    void saveAndFind() {
        EmployeeRedisEntity employee = new EmployeeRedisEntity(0, "zero", 2);
        employRepositoryString.save(employee);
        // 직접 비교 하면 인 메모리에 저장된 주소 비교 하기 때문에 값이 다르다...아마???
        Assertions.assertThat(employRepositoryString.getEmployeeById(0).getSalary()).isEqualTo(employee.getSalary());
    }

    @Test
    void update() {
        EmployeeRedisEntity employee = new EmployeeRedisEntity(0, "zero", 13);
        employRepositoryString.update(employee);
        Assertions.assertThat(employRepositoryString.getEmployeeById(0).getSalary()).isEqualTo(13);
    }

    @Test
    void deleteById() {
        EmployeeRedisEntity employee = new EmployeeRedisEntity(0, "zero", 12);
        employRepositoryString.save(employee);
        employRepositoryString.deleteById(0);
    }
}