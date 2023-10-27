package gg.onboarding03.redis;

import java.util.Map;

public interface EmployeeRepository {
    void save(EmployeeRedisEntity employee);
    EmployeeRedisEntity getEmployeeById(Integer id);
    Map<Integer, EmployeeRedisEntity> getAllEmployees();
    void update(EmployeeRedisEntity employee);
    void deleteById(Integer id);

}
