struct ResultLogic {

  int Brightness;
  String LampCondition;

};

class LampLogic {

  public:
  
    ResultLogic Logic(int PhotoResistor) {
      
      ResultLogic Result;

      if(PhotoResistor < 517) {
        Result.Brightness = map(
          PhotoResistor + 517,
          0, 1023, 0, 255
        );

        Result.LampCondition = "Lampu Menyala";

      } else {

        Result.Brightness = 0;
        Result.LampCondition = "Lampu Mati";
      }

      return Result;
    }
    
};