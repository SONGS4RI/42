package gg.onboarding03.redis;

import org.springframework.data.repository.CrudRepository;

// JpaData 랑 비슷한 느낌
public interface EmployeeCrudRepository extends CrudRepository<EmployeeRedisEntity, Integer> {
}
