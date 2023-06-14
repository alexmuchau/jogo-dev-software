class Utilities {
    public:
      int min_screen_cols;
      int min_screen_rows;
      int screen_cols;
      int screen_rows;
      void get_screen_size();
      void get_map_startxy(double * start_y, double * start_x);
      bool screen_verification();
      Utilities();
};
