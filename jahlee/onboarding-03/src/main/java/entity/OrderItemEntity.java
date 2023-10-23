package entity;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;

@Entity
@Getter @Setter
public class OrderItemEntity {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @ManyToOne
    @JoinColumn(name = "ORDER_ID")
    private OrdersEntity ordersEntity;

//    @ManyToOne
//    @JoinColumn(name = "ITEM_ID")
//    private ItemEntity item;

    private int orderPrice;
    private int count;

}
