package gg.onboarding03.redis;

import org.springframework.data.redis.core.HashOperations;
import org.springframework.stereotype.Repository;

import javax.annotation.Resource;
import java.util.Map;

@Repository
public class EmployeeRepositoryStringImpl implements EmployeeRepository {
    String key = "employee";
    // @Resource 를 사용 해서 빈에서 탐색해 주입 하는 방식도 존재 한다.
    // @Autowired RedisTemplate<String, String> redisTemplate;
    // private ValueOperations<String, String> valueOperations = redisTemplate.opsForValue();
    @Resource(name = "redisTemplate")
    private HashOperations<String, Integer, EmployeeRedisEntity> hashOperations;
    @Override
    public void save(EmployeeRedisEntity employee) {
        hashOperations.putIfAbsent(key, employee.getId(), employee);
    }
    @Override
    public EmployeeRedisEntity getEmployeeById(Integer id) {
        return hashOperations.get(key, id);
    }

    @Override
    public Map<Integer, EmployeeRedisEntity> getAllEmployees() {
        return hashOperations.entries(key);
    }

    @Override
    public void update(EmployeeRedisEntity employee) {
        hashOperations.put(key, employee.getId(), employee);
    }

    @Override
    public void deleteById(Integer id) {
        hashOperations.delete(key, id);
    }
}
