package gg.onboarding03.entity;

import javax.persistence.Entity;
import javax.persistence.Table;

@Entity
@Table(name = "MOVIE")
public class MovieEntity extends ItemEntity{
    private String director;
    private String actor;
}
