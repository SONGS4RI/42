package gg.onboarding03.entity;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Getter @Setter
@Table(name = "ORDERS")
public class OrderEntity extends BaseEntity {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @ManyToOne//done
    @JoinColumn(name = "MEMBER_ID")
    private MemberEntity member;

    @OneToMany(mappedBy = "order")//done
    private List<OrderItemEntity> orderItem = new ArrayList<>();

    @OneToOne//done
    @JoinColumn(name = "DELIVERY_ID")
    private DeliveryEntity delivery;

    private OrderStatus orderStatus;
}
