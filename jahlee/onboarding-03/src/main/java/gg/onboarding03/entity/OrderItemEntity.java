package gg.onboarding03.entity;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;

@Entity
@Getter @Setter
@Table(name = "ORDER_ITEM")
public class OrderItemEntity {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @ManyToOne//단방향 주인
    @JoinColumn(name = "ITEM_ID")
    private ItemEntity item;

    @ManyToOne//done
    @JoinColumn(name = "ORDER_ID")
    private OrderEntity order;

    private int orderPrice;
    private int count;

}
