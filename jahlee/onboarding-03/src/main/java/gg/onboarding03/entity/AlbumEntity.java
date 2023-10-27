package gg.onboarding03.entity;

import javax.persistence.Entity;
import javax.persistence.Table;

@Entity
@Table(name = "ALBUM")
public class AlbumEntity extends ItemEntity {
    private String artist;
    private String etc;
}
