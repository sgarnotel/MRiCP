#ifndef DIALOGSTATS_H
#define DIALOGSTATS_H


#include "headers.hpp"
#include "TextDef__Stats.h"


/*!
 * \brief The DialogStats class
 *
 * This class contains dialog box for statistic analysis of data.
 */
class DialogStats : public QDialog
{
    Q_OBJECT
public:
    explicit DialogStats(QWidget *parent = 0);

private slots:
    void resizeEvent(QResizeEvent*);
    void closeEvent(QCloseEvent *);

    void init_var();
    void init_win();
    void init_sig();
    void init_css();

    void load();
    void clear();
    void quit();
    void pre_plot();
    void plot_xy_curve(QVector<double> x, QVector<double> y);
    void zoom();
    void regression();
    void plot_regression_curve(QVector<double> x, QVector<double> y);
    void do_clustering();
    void plot_clustering(QVector<double> *x, QVector<double> *y, int k);
    void list_select();
    void plot_hightlight(QVector<double> x, QVector<double> y);
    void export2csv();

    void get_patient(QMouseEvent *m_event);

private:
    //Grid
    QGridLayout *grid;
    QGridLayout *grid_button;
    QGridLayout *grid_labels;
    QGridLayout *grid_list;
    QGridLayout *grid_box;
    QGridLayout *grid_button2;

    //List
    QListWidget *loaded_list;

    //Data
    QVector<double> current_x;
    QVector<double> current_y;

    QVector<string> highlight_name;
    QVector<double> highlight_x;
    QVector<double> highlight_y;

    QVector<QString> names;
    QVector<double> id;

    QVector<int> arterial_cervical_qualities;
    QVector<int> venous_cervical_qualities;
    QVector<int> csf_cervical_qualities;
    QVector<int> arterial_cerebral_qualities;
    QVector<int> venous_cerebral_qualities;
    QVector<int> csf_cerebral_qualities;
    QVector<int> ICP_qualities;

    QVector<double> arterial_cervical_mean_cycles;
    QVector<double> arterial_cervical_heart_rates;

    QVector<double> arterial_cervical_mins;
    QVector<double> arterial_cervical_maxs;
    QVector<double> arterial_cervical_means;
    QVector<double> arterial_cervical_grads;
    QVector<double> arterial_cervical_strokes;

    QVector<double> venous_cervical_mins;
    QVector<double> venous_cervical_maxs;
    QVector<double> venous_cervical_means;
    QVector<double> venous_cervical_grads;
    QVector<double> venous_cervical_strokes;

    QVector<double> alphas_cervical;
    QVector<double> venous_corr_cervical_mins;
    QVector<double> venous_corr_cervical_maxs;
    QVector<double> venous_corr_cervical_means;
    QVector<double> venous_corr_cervical_grads;
    QVector<double> venous_corr_cervical_strokes;

    QVector<double> csf_cervical_mean_cycles;
    QVector<double> csf_cervical_heart_rates;

    QVector<double> csf_cervical_mins;
    QVector<double> csf_cervical_maxs;
    QVector<double> csf_cervical_means;
    QVector<double> csf_cervical_grads;
    QVector<double> csf_cervical_strokes;

    QVector<double> mean_csfs_cervical;
    QVector<double> csf_corr_cervical_mins;
    QVector<double> csf_corr_cervical_maxs;
    QVector<double> csf_corr_cervical_means;
    QVector<double> csf_corr_cervical_grads;
    QVector<double> csf_corr_cervical_strokes;

    QVector<double> AV_ICVC_ratio_cervical;

    QVector<double> arteriovenous_flow_cervical_mins;
    QVector<double> arteriovenous_flow_cervical_maxs;
    QVector<double> arteriovenous_flow_cervical_means;
    QVector<double> arteriovenous_flow_cervical_grads;
    QVector<double> arteriovenous_flow_cervical_strokes;

    QVector<double> arteriovenous_volume_cervical_mins;
    QVector<double> arteriovenous_volume_cervical_maxs;
    QVector<double> arteriovenous_volume_cervical_means;
    QVector<double> arteriovenous_volume_cervical_grads;

    QVector<double> icvc_flow_cervical_mins;
    QVector<double> icvc_flow_cervical_maxs;
    QVector<double> icvc_flow_cervical_means;
    QVector<double> icvc_flow_cervical_grads;
    QVector<double> icvc_flow_cervical_strokes;

    QVector<double> icvc_volume_cervical_mins;
    QVector<double> icvc_volume_cervical_maxs;
    QVector<double> icvc_volume_cervical_means;
    QVector<double> icvc_volume_cervical_grads;

    QVector<double> arterial_cerebral_mean_cycles;
    QVector<double> arterial_cerebral_heart_rates;

    QVector<double> arterial_cerebral_mins;
    QVector<double> arterial_cerebral_maxs;
    QVector<double> arterial_cerebral_means;
    QVector<double> arterial_cerebral_grads;
    QVector<double> arterial_cerebral_strokes;

    QVector<double> venous_cerebral_mins;
    QVector<double> venous_cerebral_maxs;
    QVector<double> venous_cerebral_means;
    QVector<double> venous_cerebral_grads;
    QVector<double> venous_cerebral_strokes;

    QVector<double> alphas_cerebral;
    QVector<double> venous_corr_cerebral_mins;
    QVector<double> venous_corr_cerebral_maxs;
    QVector<double> venous_corr_cerebral_means;
    QVector<double> venous_corr_cerebral_grads;
    QVector<double> venous_corr_cerebral_strokes;

    QVector<double> csf_cerebral_mean_cycles;
    QVector<double> csf_cerebral_heart_rates;

    QVector<double> csf_cerebral_mins;
    QVector<double> csf_cerebral_maxs;
    QVector<double> csf_cerebral_means;
    QVector<double> csf_cerebral_grads;
    QVector<double> csf_cerebral_strokes;

    QVector<double> mean_csfs_cerebral;
    QVector<double> csf_corr_cerebral_mins;
    QVector<double> csf_corr_cerebral_maxs;
    QVector<double> csf_corr_cerebral_means;
    QVector<double> csf_corr_cerebral_grads;
    QVector<double> csf_corr_cerebral_strokes;

    QVector<double> AV_ICVC_ratio_cerebral;

    QVector<double> arteriovenous_flow_cerebral_mins;
    QVector<double> arteriovenous_flow_cerebral_maxs;
    QVector<double> arteriovenous_flow_cerebral_means;
    QVector<double> arteriovenous_flow_cerebral_grads;
    QVector<double> arteriovenous_flow_cerebral_strokes;

    QVector<double> arteriovenous_volume_cerebral_mins;
    QVector<double> arteriovenous_volume_cerebral_maxs;
    QVector<double> arteriovenous_volume_cerebral_means;
    QVector<double> arteriovenous_volume_cerebral_grads;

    QVector<double> icvc_flow_cerebral_mins;
    QVector<double> icvc_flow_cerebral_maxs;
    QVector<double> icvc_flow_cerebral_means;
    QVector<double> icvc_flow_cerebral_grads;
    QVector<double> icvc_flow_cerebral_strokes;

    QVector<double> icvc_volume_cerebral_mins;
    QVector<double> icvc_volume_cerebral_maxs;
    QVector<double> icvc_volume_cerebral_means;
    QVector<double> icvc_volume_cerebral_grads;

    QVector<double> icp_mins;
    QVector<double> icp_maxs;
    QVector<double> icp_means;
    QVector<double> icp_grads;

    QVector<double> compliance_AV_global_cervical;
    QVector<double> compliance_ICVC_global_cervical;
    QVector<double> compliance_AV_global_cerebral;
    QVector<double> compliance_ICVC_global_cerebral;

    QVector<double> compliance_AV_mins_cervical_parted;
    QVector<double> compliance_AV_maxs_cervical_parted;
    QVector<double> compliance_AV_means_cervical_parted;
    QVector<double> compliance_AV_grads_cervical_parted;

    QVector<double> compliance_AV_mins_cervical_continuous;
    QVector<double> compliance_AV_maxs_cervical_continuous;
    QVector<double> compliance_AV_means_cervical_continuous;
    QVector<double> compliance_AV_grads_cervical_continuous;

    QVector<double> compliance_ICVC_mins_cervical_parted;
    QVector<double> compliance_ICVC_maxs_cervical_parted;
    QVector<double> compliance_ICVC_means_cervical_parted;
    QVector<double> compliance_ICVC_grads_cervical_parted;

    QVector<double> compliance_ICVC_mins_cervical_continuous;
    QVector<double> compliance_ICVC_maxs_cervical_continuous;
    QVector<double> compliance_ICVC_means_cervical_continuous;
    QVector<double> compliance_ICVC_grads_cervical_continuous;

    QVector<double> compliance_AV_mins_cerebral_parted;
    QVector<double> compliance_AV_maxs_cerebral_parted;
    QVector<double> compliance_AV_means_cerebral_parted;
    QVector<double> compliance_AV_grads_cerebral_parted;

    QVector<double> compliance_AV_mins_cerebral_continuous;
    QVector<double> compliance_AV_maxs_cerebral_continuous;
    QVector<double> compliance_AV_means_cerebral_continuous;
    QVector<double> compliance_AV_grads_cerebral_continuous;

    QVector<double> compliance_ICVC_mins_cerebral_parted;
    QVector<double> compliance_ICVC_maxs_cerebral_parted;
    QVector<double> compliance_ICVC_means_cerebral_parted;
    QVector<double> compliance_ICVC_grads_cerebral_parted;

    QVector<double> compliance_ICVC_mins_cerebral_continuous;
    QVector<double> compliance_ICVC_maxs_cerebral_continuous;
    QVector<double> compliance_ICVC_means_cerebral_continuous;
    QVector<double> compliance_ICVC_grads_cerebral_continuous;

    QVector<double> reg;
    QVector<double> reg_csv;

    QVector<double> clust;

    //ComboBox
    QComboBox *box_x;
    QComboBox *box_x_weight;
    QComboBox *box_y;
    QComboBox *box_y_weight;

    //Plot
    QCustomPlot *plot_xy;

    //Button
    QPushButton *button_load;
    QPushButton *button_clear;
    QPushButton *button_plot;
    QPushButton *button_zoom;
    QPushButton *button_regression;
    QPushButton *button_clustering;
    QPushButton *button_export2csv;
    QPushButton *button_close;

    //Labels
    QLabel *label_x;
    QLabel *label_x_weight;
    QLabel *label_y;
    QLabel *label_y_weight;
    QLabel *label_n;
    QLabel *label_corr_coeff;
    QLabel *label_formula;
};

#endif // DIALOGSTATS_H
