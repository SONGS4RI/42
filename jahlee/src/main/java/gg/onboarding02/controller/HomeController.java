package gg.onboarding02.controller;

import gg.onboarding02.domain.PostEntity;
import gg.onboarding02.repository.H2PostRepository;
import org.apache.coyote.Response;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

import java.util.List;

@Controller
public class HomeController {
    private H2PostRepository h2PostRepository;

    @Autowired
    public HomeController(H2PostRepository h2PostRepository) {
        this.h2PostRepository = h2PostRepository;
    }

    @GetMapping("/")
    public String home(Model model) {
        List<PostEntity> list = h2PostRepository.findAll();
        model.addAttribute("posts", list);
        return "home";
    }

    @PostMapping("/new")
    public String create(PostForm form) {
        if (form.getName().isEmpty() || form.getText().isEmpty()) return "redirect:/";
        PostEntity post = new PostEntity();
        post.setName(form.getName());
        post.setText(form.getText());
        h2PostRepository.save(post);
        return "redirect:/";
    }
}
