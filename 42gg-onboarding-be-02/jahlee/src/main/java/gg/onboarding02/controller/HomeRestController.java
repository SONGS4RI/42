package gg.onboarding02.controller;

import gg.onboarding02.domain.PostEntity;
import gg.onboarding02.repository.H2PostRepository;
import org.apache.coyote.Response;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;
import java.util.Optional;

//@RestController
public class HomeRestController {
    private H2PostRepository h2PostRepository;

//    @Autowired
    public HomeRestController(H2PostRepository h2PostRepository) {
        this.h2PostRepository = h2PostRepository;
    }

    @GetMapping("/")
    public String home(Model model) {
        List<PostEntity> list = h2PostRepository.findAll();
        model.addAttribute("posts", list);
        return "home";
    }

    @PostMapping("/new")
    public Optional<PostEntity> create(@RequestParam("name")String name, @RequestParam("text")String text) {
        if (name.isEmpty() || text.isEmpty()) return Optional.empty();
        PostEntity post = new PostEntity();
        post.setName(name);
        post.setText(text);
        h2PostRepository.save(post);
        return Optional.of(post);
    }
}

