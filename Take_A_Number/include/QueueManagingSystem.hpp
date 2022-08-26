using qnumber = int;

class QueueManagingSystem{
    QueueManagingSystem(){};

    qnumber GetNextAvailableNumber();
    qnumber GetNextDeliveryNumber();

private:
    qnumber current_available_number;
    qnumber current_delivery_number;

};