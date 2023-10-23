package entity;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Getter @Setter
public class MemberEntity {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String name;
    @Embedded
    private Address address;

    @OneToMany
    private List<OrdersEntity> orders = new ArrayList<OrdersEntity>();

//    public Optional<OrdersEntity> addOrder() {
//    }
}
