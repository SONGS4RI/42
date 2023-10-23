package gg.onboarding02.repository;

import gg.onboarding02.domain.PostEntity;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.validation.annotation.Validated;

import javax.persistence.EntityManager;
import java.util.List;
import java.util.Optional;


@Repository
@Transactional
@Validated
public class H2PostRepository implements PostRepository {
    private final EntityManager em;

    public H2PostRepository(EntityManager em) {
        this.em = em;
    }
    @Override
    public PostEntity save(PostEntity post) {
        em.persist(post);
        return post;
    }

    @Override
    public Optional<PostEntity> findById(Long id) {
        PostEntity postEntity = em.find(PostEntity.class, id);
        return Optional.ofNullable(postEntity);
    }

    @Override
    public List<PostEntity> findAll() {
        return em.createQuery("select p from PostEntity p", PostEntity.class)
                .getResultList();
    }
    @Override
    public Optional<PostEntity> updateNameById(Long id, String name) {
        PostEntity postEntity = em.find(PostEntity.class, id);
        postEntity.setName(name);
        return Optional.of(postEntity);
    }

    @Override
    public Optional<PostEntity> updateTextById(Long id, String text) {
        PostEntity postEntity = em.find(PostEntity.class, id);
        postEntity.setText(text);
        return Optional.of(postEntity);
    }

    @Override
    public Optional<PostEntity> deleteById(Long id) {
        em.remove(em.find(PostEntity.class, id));
        return Optional.empty();
    }
}
