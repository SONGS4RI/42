package gg.onboarding02.repository;

import gg.onboarding02.domain.PostEntity;

import java.util.List;
import java.util.Optional;

public interface PostRepository {
    PostEntity save(PostEntity post);
    Optional<PostEntity> findById(Long id);
    List<PostEntity> findAll();
    Optional<PostEntity> updateNameById(Long id, String name);
    Optional<PostEntity> updateTextById(Long id, String text);
    Optional<PostEntity> deleteById(Long id);

}
