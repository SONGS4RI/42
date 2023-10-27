package gg.onboarding03.entity;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;

@Entity
@Getter @Setter
@Table(name = "DELIVERY")
public class DeliveryEntity {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @OneToOne(mappedBy = "delivery")//done
    private OrderEntity order;
    @Embedded
    private Address address;
    private DeliveryStatus status;

}
