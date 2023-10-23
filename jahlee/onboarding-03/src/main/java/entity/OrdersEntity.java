package entity;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Getter @Setter
public class OrdersEntity extends BaseEntity {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @ManyToOne
    @JoinColumn(name = "MEMBER_ID")
    private MemberEntity member;

    @OneToMany
    private List<OrderItemEntity> orderItem = new ArrayList<OrderItemEntity>();

    @OneToOne
    @JoinColumn(name = "DELIVERY_ID")
    private DeliveryEntity delivery;

    private OrderStatus orderStatus;
}
