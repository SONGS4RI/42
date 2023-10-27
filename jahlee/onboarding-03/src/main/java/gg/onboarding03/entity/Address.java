package gg.onboarding03.entity;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

@Getter @Setter
@AllArgsConstructor
public class Address {
    private String city;
    private String street;
    private String zipCode;
}
