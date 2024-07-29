package gg.onboarding02.repository;

import gg.onboarding02.domain.PostEntity;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.annotation.Rollback;
import org.springframework.transaction.annotation.Transactional;

import javax.persistence.EntityManager;

import java.util.Optional;

import static org.assertj.core.api.Assertions.assertThat;

//import static org.assertj.core.api.Assertions.assertThat;

@SpringBootTest
@Transactional
@Rollback(false)
class H2PostRepositoryTest {

    @Autowired private H2PostRepository h2PostRepository;
    @Autowired private EntityManager em;

    @Test
    void findById() {
        PostEntity postEntity = new PostEntity();
        postEntity.setName("how to spring");
        postEntity.setText("i don't know");
        h2PostRepository.save(postEntity);
        Optional<PostEntity> result = h2PostRepository.findById(postEntity.getId());
        assertThat(postEntity.getName()).isEqualTo(result.get().getName());
        assertThat(postEntity.getText()).isEqualTo(result.get().getText());
    }

    @Test
    void updateNameById() {
        PostEntity postEntity = new PostEntity();
        postEntity.setName("name 1");
        postEntity.setText("first text");
        h2PostRepository.save(postEntity);
        Optional<PostEntity> result = h2PostRepository.findById(postEntity.getId());
        h2PostRepository.updateNameById(result.get().getId(), "name 2");
        assertThat(result.get().getName()).isEqualTo("name 2");
    }

    @Test
    void updateTextById() {
        PostEntity postEntity = new PostEntity();
        postEntity.setName("name 1");
        postEntity.setText("first text");
        h2PostRepository.save(postEntity);
        Optional<PostEntity> result = h2PostRepository.findById(postEntity.getId());
        h2PostRepository.updateTextById(result.get().getId(), "second text");
        assertThat(result.get().getText()).isEqualTo("second text");
    }

    @Test
    void deleteById() {
        PostEntity postEntity = new PostEntity();
        postEntity.setName("name 1");
        postEntity.setText("first text");
        h2PostRepository.save(postEntity);
        Long id = h2PostRepository.findById(postEntity.getId()).get().getId();
        h2PostRepository.deleteById(id);
    }
}