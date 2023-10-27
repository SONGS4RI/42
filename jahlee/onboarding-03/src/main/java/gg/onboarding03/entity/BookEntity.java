package gg.onboarding03.entity;

import javax.persistence.Entity;
import javax.persistence.Table;

@Entity
@Table(name = "BOOK")
public class BookEntity extends ItemEntity {
    private String author;
    private String isbn;

}
