#ifndef UTIL_NET_H
#define UTIL_NET_H

#include "caffe2/core/operator.h"

namespace caffe2 {

class NetUtil {
 public:
  NetUtil(NetDef& net):
    net_(net) {}

  OperatorDef* AddOp(const std::string& name, const std::vector<std::string>& inputs, const std::vector<std::string>& outputs);

  OperatorDef* AddCreateDbOp(const std::string& reader, const std::string& db_type, const std::string& db_path);
  OperatorDef* AddTensorProtosDbInputOp(const std::string& reader, const std::string& data, const std::string& label, int batch_size);
  OperatorDef* AddCoutOp(const std::vector<std::string>& params);
  OperatorDef* AddZeroOneOp(const std::string& pred, const std::string& label);
  OperatorDef* AddShowWorstOp(const std::string& pred, const std::string& label, const std::string& data);
  OperatorDef* AddEnsureCpuOutputOp(const std::string& input, const std::string& output);
  OperatorDef* AddCopyFromCpuInputOp(const std::string& input, const std::string& output);
  OperatorDef* AddCopyOp(const std::string& input, const std::string& output);
  OperatorDef* AddCreateMutexOp(const std::string& param);
  OperatorDef* AddPrintOp(const std::string& param, bool to_file = false);
  OperatorDef* AddSummarizeOp(const std::string& param, bool to_file = false);

  OperatorDef* AddConstantFillOp(const std::vector<int>& shape, const std::string& param);
  OperatorDef* AddXavierFillOp(const std::vector<int>& shape, const std::string& param);
  OperatorDef* AddUniformFillOp(const std::vector<int>& shape, float min, float max, const std::string& param);
  OperatorDef* AddConstantFillOp(const std::vector<int>& shape, float value, const std::string& param);
  OperatorDef* AddConstantFillOp(const std::vector<int>& shape, int64_t value, const std::string& param);
  OperatorDef* AddConstantFillWithOp(float value, const std::string& input, const std::string& output);
  OperatorDef* AddVectorFillOp(const std::vector<int>& values, const std::string& name);
  OperatorDef* AddGivenTensorFillOp(const TensorCPU& tensor, const std::string& name);

  OperatorDef* AddConvOp(const std::string& input, const std::string& w, const std::string& b, const std::string& output, int stride, int padding, int kernel);
  OperatorDef* AddReluOp(const std::string& input, const std::string& output);
  OperatorDef* AddLrnOp(const std::string& input, const std::string& output, int size, float alpha, float beta, float bias, const std::string& order = "NCHW");
  OperatorDef* AddMaxPoolOp(const std::string& input, const std::string& output, int stride, int padding, int kernel, const std::string& order = "NCHW");
  OperatorDef* AddAveragePoolOp(const std::string& input, const std::string& output, int stride, int padding, int kernel, const std::string& order = "NCHW");
  OperatorDef* AddFcOp(const std::string& input, const std::string& w, const std::string& b, const std::string& output, int axis = 1);
  OperatorDef* AddDropoutOp(const std::string& input, const std::string& output, float ratio);
  OperatorDef* AddSoftmaxOp(const std::string& input, const std::string& output, int axis = 1);
  OperatorDef* AddConcatOp(const std::vector<std::string>& inputs, const std::string& output, const std::string& order = "NCHW");
  OperatorDef* AddLSTMUnitOp(const std::vector<std::string>& inputs, const std::vector<std::string>& outputs, int drop_states = 0, float forget_bias = 0.f);
  OperatorDef* AddRecurrentNetworkOp(const std::string &seq_lengths, const std::string &hidden_init, const std::string &cell_init, const std::string &scope, const std::string &hidden_output, const std::string &cell_state, bool force_cpu);

  OperatorDef* AddAccuracyOp(const std::string& pred, const std::string& label, const std::string& accuracy, int top_k = 0);
  OperatorDef* AddLabelCrossEntropyOp(const std::string& pred, const std::string& label, const std::string& xent);
  OperatorDef* AddAveragedLossOp(const std::string& input, const std::string& loss);
  OperatorDef* AddDiagonalOp(const std::string& input, const std::string& diagonal, const std::vector<int>& offset);
  OperatorDef* AddBackMeanOp(const std::string& input, const std::string& mean, int count = 1);
  OperatorDef* AddMeanStdevOp(const std::string& input, const std::string& mean, const std::string& scale);
  OperatorDef* AddAffineScaleOp(const std::string& input, const std::string& mean, const std::string& scale, const std::string& transformed, bool inverse = false);
  OperatorDef* AddSliceOp(const std::string& input, const std::string& output, const std::vector<std::pair<int, int>>& ranges);
  OperatorDef* AddReshapeOp(const std::string& input, const std::string& output, const std::vector<int>& shape);

  OperatorDef* AddWeightedSumOp(const std::vector<std::string>& inputs, const std::string& sum);
  OperatorDef* AddSumOp(const std::vector<std::string>& inputs, const std::string& sum);
  OperatorDef* AddMomentumSgdOp(const std::string& param, const std::string& moment, const std::string& grad, const std::string& lr);
  OperatorDef* AddAdagradOp(const std::string& param, const std::string& moment, const std::string& grad, const std::string& lr);
  OperatorDef* AddAdamOp(const std::string& param, const std::vector<std::string>& moments, const std::string& grad, const std::string& lr, const std::string& iter);
  OperatorDef* AddScaleOp(const std::string& input, const std::string& output, float scale);
  OperatorDef* AddClipOp(const std::string& input, const std::string& output, float min, float max);
  OperatorDef* AddCastOp(const std::string& input, const std::string& output, TensorProto::DataType type);
  OperatorDef* AddStopGradientOp(const std::string& param);
  OperatorDef* AddIterOp(const std::string& iter);
  OperatorDef* AddAtomicIterOp(const std::string& mutex, const std::string& iter);
  OperatorDef* AddLearningRateOp(const std::string& iter, const std::string& rate, float base_rate, float gamma = 0.999f);
  OperatorDef* AddCheckpointOp(const std::vector<std::string>& inputs, int every, const std::string &db_type, const std::string &db);

  void AddInput(const std::string input);
  void AddOutput(const std::string output);
  void SetName(const std::string name);
  void SetType(const std::string type);

  void SetFillToTrain();
  void SetRenameInplace();
  void SetEngineOps(const std::string engine);

  OperatorDef* AddGradientOp(OperatorDef &op);
  void AddGradientOps();

  std::map<std::string, int> CollectParamSizes();
  std::vector<std::string> CollectParams();
  std::vector<OperatorDef> CollectGradientOps();
  std::set<std::string> CollectLayers(const std::string &layer, bool forward = false);

  void CheckLayerAvailable(const std::string &layer);
  std::string Proto();
  void Print();


 protected:
   NetDef& net_;
};

}  // namespace caffe2

#endif  // UTIL_NET_H
