class Gas {
   private:
      double fo2;
      double pressure;
   public:
      Gas(double fo2, double pressure) {
         this->fo2 = fo2;
         this->pressure = pressure;
      }

      double get_fo2();
      double get_pressure();
      double get_ppo2();
};

