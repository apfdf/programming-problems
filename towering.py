
inp_r = list(map(int, input().split()))

box_lengths = inp_r[0:6]

tower_length_a = inp_r[6]
tower_length_b = inp_r[7]

for i in range(6):
    for j in range(6):
        for k in range(6):
            if i != j and j != k and box_lengths[i] + box_lengths[j] + box_lengths[k] == tower_length_a:
            
                boxes_a = sorted([box_lengths[i], box_lengths[j], box_lengths[k]], reverse=True)
                boxes_b = sorted(list(filter(lambda x: x not in boxes_a, box_lengths)), reverse=True)
                    
                print(*(boxes_a + boxes_b))
                
                quit()

